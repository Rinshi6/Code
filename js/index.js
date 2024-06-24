let marks={
    harry:90,
    rinshi:95,
    komal:10
}
for(let i=0;i<Object.keys(marks).length;i++){
    console.log("marks of ",Object.keys(marks)[i]," is ",marks[Object.keys(marks)[i]])
}

for(let x in marks){
    console.log("marks of ",x," is ",marks[x])
}