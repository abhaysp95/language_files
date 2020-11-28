package main

import "fmt"

/* started with D so can be exported from package, same with field
* names(number, actorName, companions) they are small so can't be exported */
type Doctor struct {
	number     int
	actorName  string
	companions []string
}

/* composition */
type Animal struct {
	Name   string
	Origin string
}

type Bird struct {
	Animal   // this tells to embed the struct to current struct
	SpeedKPH float32
	CanFly   bool
}

type NSPoint struct {
	x float32
	y float32
}

type NSRect struct {
	origin NSPoint
	target NSPoint
}

/** main function */

func main() {
	map1 := make(map[[3]int]string)
	map1 = map[[3]int]string{
		{1, 2, 3}: "first",
		{4, 5, 6}: "second",
		{7, 8, 9}: "third",
	}
	fmt.Printf("map1: %v, %T\n", map1, map1)
	var map2 map[string]int = map[string]int{
		"fname": 1,
		"sname": 2,
		"tname": 3,
	}
	fmt.Printf("map1: %v, %T\n", map2, map2)

	/* order in a map can't be guarenteed */
	map1[[3]int{10, 11, 12}] = "fourth"
	fmt.Printf("map1: %v, %T\n", map1, map1)
	key := [3]int{4, 5, 6}
	var gotArr string = map1[key]
	var gotArr1 string = map1[[3]int{7, 8, 9}]
	fmt.Printf("gotArr: %v\n", gotArr)
	fmt.Printf("gotArr1: %v\n", gotArr1)
	delete(map1, [3]int{1, 2, 3})
	fmt.Printf("map1: %v, %T\n", map1, map1)
	//fmt.Printf("random: %v", delete([3]int{1, 2, 3}, 2))
	/* above will not work cause first argument should be a map */

	/* if we check the deleted keys value again, we'll get 0 again, if
	* mis-spelled key will get 0 as value again, so better interrogation of map
	* is required, in mycase it returs blank(string), see below */
	pop, ok := map1[[3]int{1, 2, 3}] // known as comma-ok syntax
	fmt.Printf("%v, %v, %T\n", pop, ok, pop)
	pop1, ok1 := map1[[3]int{4, 5, 6}] // known as comma-ok syntax
	fmt.Printf("%v, %v\n", pop1, ok1)
	// use _ if you just want to check the status of presence in place of
	// actual var name to hold the value after execution
	fmt.Printf("len map1: %v\n", len(map1))

	map3 := map1
	delete(map3, [3]int{10, 11, 12})
	fmt.Printf("map3: %v, %T\n", map3, map3)
	fmt.Printf("map1: %v, %T\n", map1, map1)

	/** struct */
	aDoctor := Doctor{
		number:    3,
		actorName: "Jon Pertwee",
		companions: []string{
			"Liz Shaw",
			"Jo Grant",
			"Sarah Jane Smith",
		},
	}
	fmt.Printf("%v, Type = %T\n", aDoctor, aDoctor)
	fmt.Println(aDoctor.actorName)
	fmt.Println(aDoctor.companions[2])
	/* you can also have just values in struct, but not recommended unless needed */

	var testDoctor Doctor = Doctor{
		number:    3,
		actorName: "Something",
	}
	fmt.Printf("%v, type = %T\n", testDoctor, testDoctor)
	/* testDoctor is actual type of main.Doctor, but since the package is same
	* it works */

	/* Anonymous struct */
	bDoctor := struct{ name string }{name: "John Pertwee"}
	cDoctor := bDoctor // can use &bDoctor if you want to point to bDoctor and not copy it
	fmt.Println(bDoctor)
	cDoctor.name = "Tom Baker"
	fmt.Println(cDoctor)

	/* composition */
	bird := Bird{}
	bird.Name = "Emu"
	bird.Origin = "Australia"
	bird.SpeedKPH = 48
	bird.CanFly = false
	fmt.Println(bird)
	fmt.Printf("Type of Bird: %T\n", bird)
	/* so, there no relation of bird with Animal, it's just syntactic sugar
	* from go, which makes the use of embedded struct, as said it's not a
	* tradition inheritance relationship but a compistion  */

	var anotherBird Bird = Bird{
		Animal: Animal{
			Name:   "Eagle",
			Origin: "Eurasia",
		},
		SpeedKPH: 65,
		CanFly:   true,
	}
	fmt.Println(anotherBird)

	var point NSPoint = NSPoint{
		x: 0,
		y: 0,
	}
	fmt.Println(point)

	rect := NSRect{
		origin: NSPoint{x: 0, y: 0},
		target: NSPoint{x: 100, y: 150},
	}
	fmt.Println(rect)
	fmt.Printf("Target is: %v\n", rect.target)

	var anotherRect NSRect = NSRect{}
	anotherRect.origin.x = 0
	anotherRect.origin.y = 0
	anotherRect.target.x = 240
	anotherRect.target.y = -85
	fmt.Println(anotherRect)

	/*var anotherRect NSRect = NSRect{
		origin.x: 0,
		origin.y: 0,
		target.x: -150,
		target.y: 75,
	}
	fmt.Println(anotherRect)
	fmt.Printf("Target is: %v\n", anotherRect.target)*/

	/* now the above one doesn't works, so is rect the only way */
}
