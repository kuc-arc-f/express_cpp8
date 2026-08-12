import koffi from "koffi"

const LibLoad = {
  getLib: function(){
    const lib = koffi.load("./libsample.so");
    return lib;
  },
}
export default LibLoad;
