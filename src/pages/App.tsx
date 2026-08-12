import * as React from 'react';

console.log("env=", process.env.NODE_ENV)

/*
      {(process.env.NODE_ENV === "production") ? (
          <script type="module" src="/js/client.js"></script>
      ): (
          <script type="module" src="/public/js/client.js"></script>
      )}
*/
export default function Page() { 
  return (
  <html>
    <head>
      <title>welcome</title>
      <script src="https://cdn.jsdelivr.net/npm/@tailwindcss/browser@4"></script>
    </head>
    <body>
      <div id="app"></div>
      <script type="module" src="/js/client.js"></script>
    </body>

  </html>
  );
}
