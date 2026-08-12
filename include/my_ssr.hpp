#pragma once
#include <iostream>
#include <string>

class MySsr {
private:
  std::string m_name = "";

public:
    explicit MySsr(std::string str){}
    ~MySsr() {}

    std::string ssr_htm_top(){
        std::string ret = "";

        std::string text = R"(<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>HTMX Todo App</title>
    <script src="https://unpkg.com/htmx.org@1.9.12"></script>
    <script src="https://cdn.jsdelivr.net/npm/@tailwindcss/browser@4"></script>
    <script src="/js/client.js"></script>
  </head>
  <body class="bg-stone-100 min-h-screen flex justify-center text-stone-900 font-sans">
    <div class="max-w-3xl mx-auto p-4 py-12" hx-get="/api/todo/list" hx-trigger="load" hx-swap="outerHTML">
      Top
      <div class="flex justify-center mt-12">
        <div class="animate-spin rounded-full h-8 w-8 border-b-2 border-stone-800"></div>
      </div>
    </div>
  </body>  
</html>
)";
        //std::cout << text << std::endl;
        ret = text;
        return ret;
    }

    std::string get_htm_about(){
        std::string ret = "";

        std::string text = R"(<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>HTMX Todo App</title>
    <script src="https://unpkg.com/htmx.org@1.9.12"></script>
    <script src="https://cdn.jsdelivr.net/npm/@tailwindcss/browser@4"></script>
  </head>
  <body class="bg-white min-h-screen text-stone-900 font-sans">
    <div>
      <a href="/" class="font-bold ms-4" >Home</a>
      <a href="/about" class="ms-4" >[ about ]</a>
      <hr class="my-2" />
    </div>      
    <div class="max-w-3xl mx-auto p-4 py-12" >
      <h1 class="font-bold text-xl" >About</h1>
      <hr /> 
    </div>
  </body>  
</html>
)";
        //std::cout << text << std::endl;
        ret = text;
        return ret;
    }

};