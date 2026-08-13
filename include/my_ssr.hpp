#pragma once
#include <iostream>
#include <string>

#include "my_type.hpp"

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


    std::string renderTodoList(const std::vector<Todo>& todos) {
        std::string html = R"(
        <div class="bg-white w-3xl rounded-xl shadow-sm border border-stone-200 overflow-hidden" id="todo-container">
        <div>
            <a href="/" class="font-bold ms-4" >Home</a>
            <a href="/about" class="ms-4" >[ about ]</a>
            <hr class="my-2" />
        </div>
        
        <div class="p-6 border-b border-stone-200">
            <h1 class="text-2xl font-semibold text-stone-800">Todo List</h1>
            <form class="mt-4 flex gap-2" hx-post="/api/todo/create" hx-target="#todo-container" hx-swap="outerHTML">
            <input type="text" name="title" required placeholder="Add a new task..." class="flex-1 px-4 py-2 border border-stone-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-stone-500 focus:border-transparent" />
            <button type="submit" class="px-4 py-2 bg-stone-800 text-white rounded-lg hover:bg-stone-700 transition-colors font-medium">Add</button>
            </form>
        </div>
        <ul class="divide-y divide-stone-100">
    )";

    for (const auto& todo : todos) {
        html += "          <li class=\"group flex items-center justify-between p-4 hover:bg-stone-50 cursor-pointer transition-colors\" \n";
        html += "              hx-get=\"/api/todo/get/" + std::to_string(todo.id) + "\" \n";
        html += "              hx-target=\"#dialog-container\" \n";
        html += "              hx-swap=\"innerHTML\">\n";
        html += "            <div class=\"flex items-center gap-3\">\n";
        html += "              <span class=\"text-stone-800 font-medium";
        html += "\">" + todo.title + "</span>\n";
        html += "            </div>\n";
        html += "            <form class=\"mt-4 flex gap-2\" hx-post=\"/api/todo/delete\" hx-target=\"#todo-container\" hx-swap=\"outerHTML\">\n";
        html += "              <input type=\"hidden\" name=\"id\"  value=\"" + std::to_string(todo.id) + "\" />\n";
        html += R"(              <button class=\"text-stone-400 hover:text-red-500 opacity-0 group-hover:opacity-100 transition-opacity p-2\"
                      onclick=\"event.stopPropagation()\">Delete
              </button>
            </form>
          </li>
        )";
    }

        if (todos.empty()) {
            html += "        <li class=\"p-8 text-center text-stone-500\">No tasks yet. Add one above!</li>\n";
        }

        html += R"(      </ul>
        <div id="dialog-container"></div>
        </div>
    )";

    return html;
}


};