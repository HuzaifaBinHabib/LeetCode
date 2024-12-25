var relativeSortArray = function (arr1, arr2) {
    let arr3 = [];
    let k = [];

    for (let i = 0; i < arr2.length; i++) {
        for (let j = 0; j < arr1.length; j++) {
            if (arr1[j] === arr2[i]) {
                arr3.push(arr1[j]);
            }
        }
    }

    for (let j = 0; j < arr1.length; j++) {
        if (!arr2.includes(arr1[j])) {
            k.push(arr1[j]);
        }
    }

    k.sort((a, b) => a - b);

    arr3 = arr3.concat(k);
    return arr3;
};