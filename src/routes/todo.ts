import express from 'express';
import LibLoad from "../../LibLoad"

const router = express.Router();

router.post('/create', async function(req, res) {
  const retObj = {ret: 500, data: null};
  try {
    const lib = LibLoad.getLib();
    const todoAdd = lib.func('char* todo_add(const char* input)');  
    const todo_list = lib.func('char* todo_list()');     
    const body = req.body
    console.log(body);
    todoAdd(body.title);
    const todo_list_elem = lib.func('char* todo_list_elem()'); 
    //console.log(body);
    const resp = todo_list_elem();
     return res.send(resp);
  } catch (error) {
    console.error(error);
    res.sendStatus(500);
  }
});

router.get('/list', async function(req, res) {
  const retObj = {ret: 500, data: null};
  try {
    const lib = LibLoad.getLib();
    const todo_list = lib.func('char* todo_list()'); 
    const todo_list_elem = lib.func('char* todo_list_elem()'); 
    const body = req.body
    //console.log(body);
    const resp = todo_list_elem();
    return res.send(resp);
  } catch (error) {
    console.error(error);
    res.sendStatus(500);
  }
});

router.get('/get/:id', async function(req, res) {
  const retObj = {ret: 500, data: null};
  try {
    const lib = LibLoad.getLib();
    const todo_list = lib.func('char* todo_list()');    
    const dialog_show = lib.func(
        "dialog_show",
        "char*",
        ["int"]
    );    
    const id = req.params.id;
    console.log("id=", id)
    const resp = dialog_show(Number(id));
    return res.send(resp);
  } catch (error) {
    console.error(error);
    res.sendStatus(500);
  }
});

router.post('/delete', async function(req, res) {
  const retObj = {ret: 500, data: null};
  try {
    const lib = LibLoad.getLib();
    //const todo_list = lib.func('char* todo_list()'); 
    const todo_delete = lib.func(
        "todo_delete",
        "int",
        ["int"]
    );   
    const body = req.body
    console.log(body);
    todo_delete(Number(body.id));
    const todo_list_elem = lib.func('char* todo_list_elem()'); 
    //console.log(body);
    const resp = todo_list_elem();
    return res.send(resp);
  } catch (error) {
    console.error(error);
    res.sendStatus(500);
  }
});

export default router;
