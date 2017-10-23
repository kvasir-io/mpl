[![Build Status](https://travis-ci.org/kvasir-io/mpl.svg?branch=development)](https://travis-ci.org/kvasir-io/mpl)

## Introduction
This repository contains the template metaprogramming library used in Kvasir. Although this started as an experiement in TMP optimization [(with quite satisfactory results)](http://metaben.ch) and we did not aim for mainstream use from the beginning this library is currently evolving to meet the needs of a broader audience. This library is intended for anyone developing C++ libraries which have a metaprogramming component and do not need the fusion style heterogenious support offered by boost.hana. 

A short list of key design decisions:
- compile time speed is paramount
- continuation style public interface
- zero cost composition of algorithms and lambdas
- seamless integration of 'continuations as lambda' syntax

## learning resources
Check out the [standardese generated docs here](http://kvasir.io/mpl/doc/standardese/standardese_entities.html). 
Throughout the design process [@odinthenerd](https://github.com/odinthenerd) has kept a [pretty thorough blog](http://odinthenerd.blogspot.de/) explaining the optimization techniques and design decisions that went into kvasir::mpl. Keep in mind that each blog piece was a snapshot in time and a few things were deprecated or changed along the way.
This library was also presented at C++Now2017 which can be found [here](https://www.youtube.com/watch?v=EtU4RDCCsiU). 

## Kvasir project
This library is part of the Kvasir project.
Kvasir is a collection of zero cost statically checked libraries for resource constrained systems including microcontrollers.
More information at kvasir.io.

## code guidelines
To keep the library performant, clean and easy to use, several guidelines have to be taken into
consideration.

- All kvasir mpl code will go into the kvasir::mpl namespace.
- All user-facing functions must be continuations except the explicit chain termination 'identity'.
- Anything that is not eager should have '_impl' or similar appended, and be in the ::detail namespace

## Contributors
We'd like to thank the following contributors, in alphabetical order:

- Nils Deppe ([@nilsdeppe](https://github.com/nilsdeppe))
- Chiel Douwes ([@chieltbest](https://github.com/chieltbest))
- Emil Fresk ([@korken89](https://github.com/korken89))
- Odin Holmes ([@odinthenerd](https://github.com/odinthenerd))
- Jonathan Poelen ([@jonathanpoelen](https://github.com/jonathanpoelen))

## Maintainer
This library is maintained by Chiel Douwes ([@chieltbest](https://github.com/chieltbest)).
Requests for push rights could be addressed to him. The maintainer is also the only one who could approve pull requests to
master.

