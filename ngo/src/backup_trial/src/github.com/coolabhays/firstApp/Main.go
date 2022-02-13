package main

import (
	"fmt"
	"math"
	"strconv"
)

var pkgLvl string = "This is at package level, you have to use full syntax of declaration here, not :="

/* Another thing which we can do at package level is that we can create a block
* of variable */

var (
	actorName    string = "Elisabeth Sladen"
	companion    string = "Sarah Jane Smith"
	doctorNumber int    = 3
	season       int    = 11
)

/* This doesn't mean that they are related but shows that they
* are related in a context */

var (
	counter int = 10
)

const pkgA int16 = 27

const (
	fi = iota // iota can be used for enumerated constant
	si = iota
	ti = iota
)

const (
	foi = iota
	fii
	sii
	/* will not give error as compiler will think that pattern has been
	* established to set const to iota in this const block */
)

const (
	// errorSpecialist = iota // this makes 0 not usable
	_ = iota + 5 // this tells compiler I don't care about this value, which will benefit us by not having iota 0 from bottom, can also add to iota
	catSpecialist
	dogSpecialist
	snakeSpecialist
)

const (
	_  = iota
	KB = 1 << (10 * iota) // increasing 2 ^ 10 everytime
	MB
	GB
	TB
	PB
	EB
	ZB
	YB
)

const (
	isAdmin = 1 << iota
	isHeadquarters
	canSeeFinancials
	canSeeAfrica
	canSeeAsia
	canSeeEurope
	canSeeNorthAmerica
	canSeeSouthAmerica
)

func main() {
	var i int // declaration
	i = 42
	var j float32 = 50.9
	k := "All are values" // go automatically figures what type is this by :=
	l := 64.              // it's float64, so when you need more control use second type for declaration and initialization
	//l = int(j)            // conversion
	m := float32(i)      // so assignment should make sense
	n := string(i)       // will print ASCII of i = 42
	o := strconv.Itoa(i) // to convert to string from int(strconv)
	fmt.Println("This is Go\n", i, "\n", j, "\n"+k)
	fmt.Printf("%v %T\n", i, i)
	fmt.Printf("%v %T\n", j, j)
	fmt.Printf("%v %T\n", k, k)
	fmt.Printf("%v %T\n", l, l)
	fmt.Printf("%v %T\n", m, m)
	fmt.Printf("%v %T\n", n, n)
	fmt.Printf("%v %T\n", o, o)
	fmt.Println(pkgLvl)

	// primitives types
	var a bool = false
	b := a == true // note: := needs new variable on the lhs
	fmt.Printf("%v %T\n", b, b)

	// go initializes varibles with 0

	/* go have int8, int16, int32, int64 and then you can use
	* math package for more big numbers, and also have
	* equivalent unsigned integer, for int64 there's no unsigned, instead there's byte */
	var c uint64 = 43 // but I have unit64(idk)
	fmt.Printf("%v %T\n", c, c)
	var d byte = 255 // 8 bit unsigned int is byte(max: 255)
	fmt.Printf("%v %T\n", d, d)

	var e byte = 8
	fmt.Println(e << 3) // 2^3 * 2^3 = 2^6
	fmt.Println(e << 3) // 2^3 / 2^3 = 2^0
	fmt.Println(e >> 3)

	// IEE754 std., float32 and float64
	f := 3.14
	g := 13.7e72
	h := 2.1e14
	fmt.Printf("%v %T\n", f, f)
	fmt.Printf("%v %T\n", g, g)
	fmt.Printf("%v %T\n", h, h)

	/* complex number */
	var p complex64 = 1 + 2i    /* also have complex128 */
	fmt.Printf("%v %T\n", p, p) // have +, -, *, / operations
	fmt.Printf("%v %T\n", real(p), real(p))
	fmt.Printf("%v %T\n", imag(p), imag(p))

	var q complex128 = complex(10, -5)
	fmt.Printf("%v %T\n", q, q)

	/* strings */
	s := "This is String"
	fmt.Printf("%v, %T\n", s[2], s[2])
	/* s is an alias of type byte */
	fmt.Printf("%v, %T\n", string(s[2]), string(s[2]))
	//s[2] = "u"  /* not allowed */
	fmt.Printf("%v, %T\n", string(s[2]), string(s[2]))

	/* supports string concatenation */
	sliceOfBytes := []byte(s)
	fmt.Printf("%v, %T\n", sliceOfBytes, sliceOfBytes)
	// string represents utf-8 and is uint8[] or (byte)

	// Any utf-8 char is also a utf-32 char
	var thisIsRune rune = 'a' // utf-32 or int32
	fmt.Printf("%v, %T\n", thisIsRune, thisIsRune)
	/* look for rune more */

	// if you want to export constant in go, start name with upper case, else lower case
	const myCont int = 43
	//const myConst int = math.Sin(1.57)
	// not possible cause you can't set constant to something that isn't known at compile time
	var sin float64 = math.Sin(1.57)
	fmt.Printf("%v, %T\n", sin, sin)

	var pkgA int = 14 // wins over global
	fmt.Printf("%v, %T\n", pkgA, pkgA)

	const implicitConst = 42
	var toAdd int16 = 20
	fmt.Printf("%v, %T\n", implicitConst+toAdd, implicitConst+toAdd)
	/* in above example implicitConst is changed to int16 from int */

	fmt.Printf("%v\n", fi)
	fmt.Printf("%v\n", si)
	fmt.Printf("%v\n", ti)
	/* iota is changing its value as constant is being evaluated */

	fmt.Printf("%v\n", foi)
	fmt.Printf("%v\n", fii)
	fmt.Printf("%v\n", sii)
	/* iota resets the value out of the const block */

	/* This helps in having related counters togather */

	/* let's see a example */
	var specialistType int = snakeSpecialist
	fmt.Printf("%v\n", specialistType == snakeSpecialist)

	fileSize := 400000000000.
	fmt.Printf("%v %T\n", fileSize, fileSize)
	fmt.Printf("%.2f %T\n", fileSize/GB, fileSize/GB)

	var roles byte = isAdmin | canSeeFinancials | canSeeEurope | canSeeNorthAmerica | canSeeSouthAmerica | canSeeAsia | canSeeAfrica
	fmt.Printf("%b, %v, %T\n", roles, roles, roles)
	fmt.Printf("Is Admin? %v\n", isAdmin&roles == isAdmin)
	fmt.Printf("Is HQ? %v\n", isAdmin&roles == isHeadquarters)
}
