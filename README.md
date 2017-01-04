# MPL
This repository contains the template metaprogramming library used in Kvasir. Having Kvasir as the only dependency (at least initially) allows us to experiment more freely with improvements in the metaprogramming field. 

A short list of key design decisions: 
- compile time speed above all else (especially for large lists)
- all eager interfaces (inspired by [Bruno Dutra's metal library](https://github.com/brunocodutra/metal))
- initially only trivial lambdas (as seen before in Peter Dimov's mp11 library)
