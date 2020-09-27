package main

func countOneBits(num int) int {
	count := 0
	for num != 0 {
		if num&1 == 1 {
			count += 1
		}
		checkNeg := num >> 1
		if checkNeg < 0 {
			num = int(uint32(checkNeg))
		}
		num = num >> 1
	}
	return count
}

func main() {
	if countOneBits(5) != 2 {
		panic("5 should have two")
	}

	if countOneBits(0) != 0 {
		panic("0 should have 0")
	}

	if countOneBits(1) != 1 {
		panic("1 should have 1")
	}

	if countOneBits(-1) != 32 {
		panic("-1 should have 32")
	}
}
