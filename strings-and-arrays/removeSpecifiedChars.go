package main

import (
	"fmt"
	"strings"
)

func removeSpecifiedFrom(target string, charsToRemove string) string {
	var str strings.Builder
	var toRemove [128]bool
	for _, charToRemove := range charsToRemove {
		toRemove[charToRemove] = true
	}
	for _, c := range target {
		if !toRemove[c] {
			str.WriteRune(c)
		}
	}
	return str.String()
}

func main() {
	res := removeSpecifiedFrom("Battle of the Vowels: Hawaii vs. Grozny", "aeiou")
	fmt.Printf("res: %+v\n", res)
}
