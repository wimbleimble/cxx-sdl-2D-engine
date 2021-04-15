# NOTES:

## TODO:
* smart pointers everywhere
* audio
* abstract away inputs - rather than specific keys have commands, i.e. left
could correspond to both a and left arrow
* viewport culling AABB COLLISION - might not be necessary: open gl will cull
for me, need to do tests when i have something more intesive.
* make mouseover properly work with rotation.
* reimplement mouseover with colliders rather than just with actor dimensions
* reimplement addActor with templates to make calling it easier

## THINGS THAT MAY CAUSE PROBLEMS LATER:
- SDLImage paths resolve based on where the application is launched, and so
if it is run from outside the directory relative paths no longer resolve from
the location of the executable.
- Just noticed this with Layer and have deleted the copy constructor, because
i was accidentally iterating over it in a for each loop without taking a
reference, meaning it was getting copied and then deleted each iteration,
which was deleting all the actors referenced in _vec. I have probably missed
this elsewhere.
- If you try to add new layers once they contain actors there most likely
will be a segmentation fault when the allocator tries to move the vector
about, because there's not a properly defined copy constructor / move
constructor.
- wow i really just need to learn how to use smart pointers already huh.