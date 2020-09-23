const removeCharsFrom = (target, charsToRemove) => {
	const re = new RegExp(`[${charsToRemove}]`, 'g')
	return target.replace(re, '')
}

const result = removeCharsFrom("Battle of the Vowels: Hawaii vs. Grozny", "aeiou")
console.log(result);
