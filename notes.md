# NOTES:

## TODO:
*	smart pointers everywhere
*	audio
*	abstract away inputs - rather than specific keys have commands, i.e. left
	could correspond to both a and left arrow
*	viewport culling AABB COLLISION - might not be necessary: open gl will cull
	for me, need to do tests when i have something more intesive.
*	tilemaps - split sprite into animated sprite and tilemap

## THINGS THAT MAY CAUSE PROBLEMS LATER:
-	SDLImage paths resolve based on where the application is launched, and so
	if it is run from outside the directory relative paths no longer resolve
	from the location of the executable.