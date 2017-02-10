# MPL
This repository contains the template metaprogramming library used in Kvasir. Having Kvasir as the only dependency (at least initially) allows us to experiment more freely with improvements in the metaprogramming field. This library is not internded to be used by the end user but serves more as a foundation for those developing the library and drivers.

A short list of key design decisions: 
- compile time speed above all else (especially for large lists)
- all eager interfaces (inspired by [Bruno Dutra's metal library](https://github.com/brunocodutra/metal))
- initially only trivial lambdas (as seen before in Peter Dimov's mp11 library)


## code guidelines
To keep the library performant, clean and easy to use, several guidelines have to be taken into 
consideration.

- All kvasir mpl code will go into the kvasir::mpl namespace.
- All user-facing functions must be eager.
- Anything that is not eager should _impl or similar appended, and be in the ::detail namespace
- Returning objects:
  - Functions returning a type should inherently be that type, see the all eager functions above
  - Functions returning a value should be implicitly convertible to it's return value
  - Functions returning a function should be a type that has a templated member ::f
    For instance, when calling a function `foo` that returns a function one would do as such:
    ```
    sort<
        foo<bar>::f, // foo returns a function
        List>
    ```
- Any function taking a list should refer to a generic struct, as to allow for special 
  implementations.
- Templated structs (except for function backend structs) should have no more than one 
  parameter. Instead the "meta monad" style should be used.