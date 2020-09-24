const binarySearch = (arr, target, lo, hi) => {
  if (!arr) return -1;
  const mid = Math.floor((hi + lo) / 2);
  if (target == arr[mid]) return mid;
  return (target < arr[mid])
    ? binarySearch(arr, target, lo, mid - 1)
    : binarySearch(arr, target, mid + 1, hi)
}

const arr = [1, 2, 3, 7, 8, 10, 12, 13];
const result1 = binarySearch(arr, 7, arr[0], arr[arr.length - 1]);
console.log(result1);

const bSearchWithSlice = (arr = [], target) => {
  if (arr.length === 0) return -1;

  const mid = Math.floor((arr.length - 1) / 2);
  if (target === arr[mid]) return mid;
  return (target < arr[mid])
    ? bSearchWithSlice(arr.slice(0, mid), target)
    : bSearchWithSlice(arr.slice(mid + 1), target)
}

const result2 = bSearchWithSlice(arr, 7)
console.log(result2);

console.assert(result1 === result2);
