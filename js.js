// Understanding JS Objects are Passed By Value or Reference...
// You can chnage any property of onbject in any function..
// but you can not re-assign a new object to passed object in function..


const obj = {
    name : " ali",
    nick : " khan"
}

function changeObj(obj) {
    obj = { name : " jawad"}
    console.log(" inside change obj " + obj.name + "  " + obj.nick);
}

function changeProp(obj) {
    obj.name = " muhammad",
    console.log("inside changeProp " + obj.name + "  " + obj.nick);
}

console.log(" before chanageProp " + obj.name + "  " + obj.nick);
changeProp(obj);
console.log("after changeProp " + obj.name + "  " + obj.nick);
console.log(" before changeObj " + obj.name + "  " + obj.nick);
changeObj(obj);
console.log("after changeObj " + obj.name + "  " + obj.nick);

