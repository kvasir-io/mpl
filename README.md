# Kvasir::mpl
This library is part of the Kvasir project.
Kvasir is a collection of zero cost statically checked libraries for resource constrained systems including microcontrollers.
More information at kvasir.io.

## Introduction
This repository contains the template metaprogramming library used in Kvasir.
Having Kvasir as the only dependency (at least initially) allows us to experiment more freely with
improvements in the metaprogramming field. This library is not intended to be used by the end user
but serves more as a foundation for those developing the library and drivers.

A short list of key design decisions:
- compile time speed above all else (especially for large lists)
- all eager interfaces (inspired by [Bruno Dutra's metal library](https://github.com/brunocodutra/metal))
- initially only trivial lambdas (as seen before in Peter Dimov's mp11 library)


## code guidelines
To keep the library performant, clean and easy to use, several guidelines have to be taken into
consideration.

- All kvasir mpl code will go into the kvasir::mpl namespace.
- All user-facing functions must be eager.
- Anything that is not eager should have '_impl' or similar appended, and be in the ::detail namespace
- Returning objects:
  - Functions returning a type should inherently be that type, see the all eager functions above
  - Functions returning a value should be implicitly convertible to it's return value
  - Functions returning a function should be a type that has a templated member ::f
    For instance, when calling a function `foo` that returns a function one would do as such:
    `remove_if<bind<std::is_same, Elem>::template f, List>`
- Any function taking a list should refer to a generic struct, as to allow for special
  implementations.
- Templated structs (except for function backend structs) should have no more than one
  parameter. Instead the "meta monad" style should be used.

## Contributors
We'd like to thank the following contributors, in alphabetical order:

- Chiel Douwes ([@chieltbest](https://github.com/chieltbest))
- Emil Fresk ([@korken89](https://github.com/korken89))
- Odin Holmes ([@odinthenerd](https://github.com/odinthenerd))

## Maintainer
This library is maintained by Chiel Douwes ([@chieltbest](https://github.com/chieltbest)).
Requests for push rights could be addressed to him. The maintainer is also the only one who could approve pull requests to
master.
