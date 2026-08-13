# express_cpp8

 Version: 0.9.1

 Author  :

 date    : 2026/08/12 
 
 update :

***

node Express C++ , HTMX TODO 

* json file save
* node 22
* LLVM CLang
* C/C++
* make
* Linux

***
## Image

![img1](/images/express_cpp8.png)

***
* LIB add

```
sudo apt install nlohmann-json3-dev
```

***
* build
```
make all
```

***
* node start
```
npm i
npm run start
```

***
* test-code
* add
```
curl -X POST -H "Content-Type: application/json" \
 -d '{"title": "test-11"}' \
 http://localhost:3000/api/todo/create
```

* list
```
curl http://localhost:3000/api/todo/list
```

***
### blog

https://zenn.dev/knaka0209/scraps/b7084214f1a41d

