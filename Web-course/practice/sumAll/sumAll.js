const sumAll = function(a ,b) {
    if(a< 0 || b < 0){
        return 'ERROR';
    }
    if( typeof a !== 'number' || typeof b !== 'number'){
        return 'ERROR';
    }
    let sum = 0;
    if(a < b){
        for(let i = a; i<=b; i++){
            sum += i;
        }
    }
    else {
        for(let i =b; i <=a; i++){
            sum += i;
        }
    }
    return sum;
}

module.exports = sumAll
