#minikube delete
minikube config unset vm-driver

# Detect the platform (similar to $OSTYPE)
OS="`uname`"

case $OS in
	"Linux")
		minikube start
		IP=172.17.0.10
		sed -i -e "s/xxxx-xxxx/172.17.0.10-172.17.0.11/g" srcs/configmap.yml
	;;
	"Darwin")
	#	minikube start --driver=virtualbox
		IP=192.168.99.110
		sed -i -e "s/xxxx-xxxx/192.168.99.110-192.168.99.111/g" srcs/configmap.yml
	;;
	*) ;;
esac

eval $(minikube docker-env)

#metallb + configmap
kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.8.1/manifests/metallb.yaml
kubectl create -f srcs/configmap.yml

#builds
docker build -t mysql_alpine srcs/mysql
kubectl apply -f srcs/k8s/mysql.yaml
docker build -t nginx_alpine srcs/nginx
docker build -t phpmyadmin_alpine srcs/phpmyadmin
docker build -t wordpress_alpine srcs/wordpress
docker build -t ftps --build-arg IP=${IP} srcs/ftps
docker build -t influxdb srcs/influxdb
docker build -t grafana srcs/grafana

kubectl exec -i $(kubectl get pods | grep mysql | cut -d" " -f1) -- mysql wordpress -u root < srcs/mysql/srcs/wordpress.sql

#deploys
kubectl apply -f srcs/k8s/nginx.yaml
kubectl apply -f srcs/k8s/ftps.yaml
kubectl apply -f srcs/k8s/influxdb.yaml
kubectl apply -f srcs/k8s/grafana.yaml
kubectl apply -f srcs/k8s/wordpress.yaml
kubectl apply -f srcs/k8s/phpmyadmin.yaml


minikube dashboard &
