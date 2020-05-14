count = 1;
function next() {
	if (count > 3) {
		count = 0;
	}
	count++;
	count = count % 5;
	document.getElementById("img").src="2020-05/image"+count+".png";
}
function prev() {
	count--;
	if (count == 0) {
		count = 4
	}
	document.getElementById("img").src="2020-05/image"+count+".png";
}

function fcol(col) {
	col.className="fcol";
}
function scol(col) {
	col.className="scol";
}
function fade_out(x) {
	x.className="fade-out"
}
