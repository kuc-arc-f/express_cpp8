
import express from 'express';
import cookieParser from "cookie-parser";

import todoRouter from './src/routes/todo';

//pages
import Top from './src/pages/Top';
import SsrAbout from './src/pages/About';

const app = express();
import 'dotenv/config'

app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(cookieParser());
app.use(express.static('public'));
console.log("env=", process.env.NODE_ENV)
//console.log(process.env);

const errorObj = {ret: "NG", messase: "Error"};

app.use('/api/todo', todoRouter);

app.get('/about', (req: any, res: any) => {
  try {
    const htm = SsrAbout();
    res.send(htm);
  } catch (error) {
    res.sendStatus(500);
  }
});
app.get('/', (req: any, res: any) => {
  try {
    const htm = Top();
    res.send(htm);
  } catch (error) {
    res.sendStatus(500);
  }
});

//start
const PORT = 3000;
app.listen({ port: PORT }, () => {
  console.log(`Start-Server: http://localhost:${PORT}`);
});
console.log('start');
