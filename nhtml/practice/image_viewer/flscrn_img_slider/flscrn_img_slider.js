// some animation related functions
function stb(size) {
	size.className="big"
}
function bts(size) {
	size.className="small"
}

let sliderContainer = document.querySelector('.slider');
let sliderImages = document.querySelectorAll('.slide');
/* querySelectorAll will return more than one(all) the matching
queries, kindof like array which we can access using index */
let leftArrow = document.querySelector('#arrow-left'),
	rightArrow = document.querySelector('#arrow-right');
let current = 0;  // will represent what image we are on

// reset all images
function reset() {
	for (let i = 0; i < sliderImages.length; i++) {
		sliderImages[i].style.display = 'none';
	}
}

// initialize slide
function startSlide() {
	reset();
	sliderImages[0].style.display = 'block';
}

// slide left
function slideLeft() {
	// setTimeout(reset, 400);
	reset();
	sliderImages[current - 1].style.display = 'block';
	current--;
}

function slideRight() {
	// setTimeout(reset, 400);
	reset();
	sliderImages[current + 1].style.display = 'block';
	current++;
}

// click to previous
leftArrow.addEventListener('click', function() {
	sliderContainer.style.opacity = 0;
	sliderContainer.style.transition = 'opacity 0.4s ease-in-out';
	if (current === 0) {
		current = sliderImages.length;
	}
	slideLeft();
	sliderContainer.style.opacity = 1;
	sliderContainer.style.transition = 'opacity 0.4s ease-in-out';
	// don't uncomment this -> sliderContainer.style.transition = 'transform 0.4s ease-in-out';
})

// click to next
rightArrow.addEventListener('click', ()=> {  // another way to add function
	sliderContainer.style.opacity = 0;
	sliderContainer.style.transition = 'opacity 0.4s ease-in-out';
	if (current === sliderImages.length - 1) {
		current = -1;
	}
	// don't uncomment this -> sliderContainer.style.transition = 'transform 0.4s ease-in-out';
	slideRight();
	sliderContainer.style.opacity = 1;
	sliderContainer.style.transition = 'opacity 0.4s ease-in-out';
})

startSlide();
