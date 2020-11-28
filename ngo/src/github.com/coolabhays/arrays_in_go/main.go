package main

import "fmt"

func main() {
	names := [...]string{"first", "middle", "last"} // array of string of size 3
	var numbers [3]int
	numbers[0] = 10
	numbers[1] = 20
	numbers[2] = 30
	var time [3]float32 = [3]float32{4.5, 5.75, 10.40}

	//var indentityMatrix [3][3]int = [3][3]int{[3]int{1, 0, 0}, [3]int{0, 1, 0}, [3]int{0, 0, 1}}

	// the above one be written in these ways as well, this removes redundacny
	var indentityMatrix [3][3]int = [3][3]int{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}

	var indentityMatrix1 [3][3]int
	indentityMatrix1[0] = [3]int{1, 0, 0}
	indentityMatrix1[1] = [3]int{0, 1, 0}
	indentityMatrix1[2] = [3]int{0, 0, 1}
	fmt.Printf("Names: %v\n", names)
	fmt.Printf("Numbers: %v\n", numbers)
	fmt.Printf("Time: %v\n", time)
	fmt.Printf("indentityMatrix: %v\n", indentityMatrix)
	fmt.Printf("indentityMatrix1: %v\n", indentityMatrix1)

	secondnames := names // copies the array not pointing to, we'll see concept of pointer later
	secondnames[1] = "second"
	thirdnames := []string{"tfirst", "tsecond", "tthrid"} // slice(array with no given size)
	fmt.Printf("Second Names: %v\n", secondnames)
	fmt.Printf("Second Names: %v\n", len(secondnames))
	fmt.Printf("Third Names: %v, %T\n", thirdnames, thirdnames)
	fmt.Printf("Third Names: %v, %T\n", thirdnames, len(thirdnames))
	fmt.Printf("Third Names: %v, %T\n", thirdnames, cap(thirdnames))
	// sometimes, cap and len differs, len tells the length of underlying array
	// while cap tells the capacity of slice
	/* we can do almost everything with slice of what we can do with arrays */

	var backArray []int = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	fmt.Printf("backArray: %v, %T\n", backArray, cap(backArray))
	slice1 := backArray[:]
	slice2 := backArray[2:6] // first number is inclusive and second is exclusive
	slice3 := backArray[:5]
	slice4 := backArray[4:]
	slice5 := backArray[:2] // must be non-negative
	fmt.Printf("backArray: %v, %T\n", backArray, cap(backArray))
	fmt.Printf("slice1, backArray[:]   :  %v, %T\n", slice1, cap(slice1))
	fmt.Printf("slice2, backArray[2:6] :  %v, %T\n", slice2, cap(slice2))
	fmt.Printf("slice3, backArray[:5]  :  %v, %T\n", slice3, cap(slice3))
	fmt.Printf("slice4, backArray[4:]  :  %v, %T\n", slice4, cap(slice4))
	fmt.Printf("slice5, backArray[:2]  :  %v, %T\n", slice5, cap(slice5))

	/* also slicing operation can work with arrays too
	change the line to "var backArray = [...]int{1, 2, ..., 10}" to check */

	/* make is used to create object of given type */
	//vmake := make([]int, 3)
	var vmake []int = make([]int, 3, 100) // param -> type, len, capacity
	fmt.Printf("vmake: %v, %T\n", vmake, vmake)
	fmt.Printf("length: %v\n", len(vmake))
	fmt.Printf("capacity: %v\n", cap(vmake))
	vmake = append(vmake, 2, 4, 5, 8, 10)
	fmt.Printf("vmake: %v, %T\n", vmake, vmake)
	fmt.Printf("length: %v\n", len(vmake))
	fmt.Printf("capacity: %v\n", cap(vmake))

	arrSlice := []int{}
	fmt.Printf("arrSlice: %v\n", arrSlice)
	fmt.Printf("Length: %v, Capacity: %v\n", len(arrSlice), cap(arrSlice))
	arrSlice = append(arrSlice, 1)
	fmt.Printf("arrSlice: %v\n", arrSlice)
	fmt.Printf("Length: %v, Capacity: %v\n", len(arrSlice), cap(arrSlice))
	arrSlice = append(arrSlice, 2, 3, 4, 5, 6)
	fmt.Printf("arrSlice: %v\n", arrSlice)
	fmt.Printf("Length: %v, Capacity: %v\n", len(arrSlice), cap(arrSlice))
	// arrSlice += slice2 // not defined
	// arrSlice += slice2... // not defined
	arrSlice = append(arrSlice, []int{10, 20, 30}...) // ... spread operator(from js) that makes it like 10, 20, 30 not slice object
	arrSlice = append(arrSlice, slice2...)
	fmt.Printf("arrSlice: %v\n", arrSlice)
	fmt.Printf("Length: %v, Capacity: %v\n", len(arrSlice), cap(arrSlice))

	/* stack operation */
	var stack []int = []int{10, 20, 30, 40, 50}
	var shift []int = stack[1:]
	var unshift []int = stack[:len(stack)-1]
	var delMid int = 3
	var midDel []int = append(stack[:delMid-1], stack[delMid:]...)
	fmt.Printf("stack: %v\n", stack)
	fmt.Printf("shift: %v\n", shift)
	fmt.Printf("unshift: %v\n", unshift)
	fmt.Printf("midDel: %v\n", midDel)
}
