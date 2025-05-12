/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    const a= new Set(nums1);
    const b= new Set(nums2);
    a.forEach((x) =>{
        if(b.has(x)){}
        else{a.delete(x);}
    })
    return [...a];

};