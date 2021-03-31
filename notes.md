# NOTES:

## TODO:
*	viewport and static entities(i.e. ui)
*	draw order - some sort of z indexing
*	smart pointers everywhere
*	audio
* abstract away inputs - rather than specific keys have commands, i.e. left
	could correspond to both a and left arrow

## THINGS THAT MAY CAUSE PROBLEMS LATER:
-	SDLImage paths resolve based on where the application is launched, and so
	if it is run from outside the directory relative paths no longer resolve
	from the location of the executable.