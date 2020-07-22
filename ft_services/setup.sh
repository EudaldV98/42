# start minikube + addons + change docker enviroment to miniukbe docker

#minikube start

#printf '\e[1;34m%-6s\e[m' "\ninstalling metallb... \n\n"

printf "installing metallb... \n\n"

#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml

printf "\n building images... \n\n"

eval $(minikube docker-env)

docker build -t nginx srcs/nginx
docker build -t ftps srcs/ftps

printf "\n running kubernetes cluster... \n\n"

#kubectl apply -f srcs/nginx.yaml
kubectl delete -f srcs/nginx/nginx.yaml && kubectl create -f srcs/nginx/nginx.yaml
kubectl delete -f srcs/ftps/ftps.yaml && kubectl create -f srcs/ftps/ftps.yaml

printf "\nopening dashboard... \n\n"

minikube dashboard &
