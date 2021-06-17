//const osm  = require('os');

//console.log(osm.type());
//console.log(osm.platform());

// custom module
const car = {
	brand: "some_brand",
	established: 1988,
	location: "this planet"
}

// module.exports = car // to export the custom module(just exposes the object)
// for property
exports.isthisacar = car  // exposes the property of the object it points to

// devdependency only required during development
// while dependency is needed in runtime, bydefault installation of node packages
