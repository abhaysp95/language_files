@interface MyAnno {
	String str();
	int val();
}

@MyAnno {
	str = "Annotation example", val = 100;
}
