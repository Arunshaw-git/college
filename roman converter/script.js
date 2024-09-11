const output = document.getElementById('output');


document.getElementById('form').addEventListener('submit',function(event){
 
    event.preventDefault();
    const numberstr= document.getElementById('number').value;
    const number = parseInt(numberstr,10);
    if (numberstr==='') {
        output.textContent = "Please enter a valid number";
        return;
      }
    else if (number >3999  ){
      output.textContent = "Please enter a number less than or equal to 3999";
      return;
    }
    else if (number <1  ){
      output.textContent = "Please enter a number  greater than or equal to 1";
      return;
    }
    else{
      const roman = toRoman(number);
      output.textContent = roman;
      return;
    }

});

function toRoman(num){
  const ref = [
    ['M', 1000],
    ['CM', 900],
    ['D', 500],
    ['CD', 400],
    ['C', 100],
    ['XC', 90],
    ['L', 50],
    ['XL', 40],
    ['X', 10],
    ['IX', 9],
    ['V', 5],
    ['IV', 4],
    ['I', 1]
  ];

  const rom =[];

  ref.forEach(function(arr) {
    while(num>=arr[1]){
      rom.push(arr[0]);
      num -=arr[1];
    }
  });
  return rom.join('');

};