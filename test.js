const torchScript = require("./build/Release/NodeScript");

const t = torchScript.moduleForward("./resnet24_se.pt", Array.from({length: 256}, v => 1));
console.log(t);


