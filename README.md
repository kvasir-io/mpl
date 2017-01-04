# MPL
This repository contains the template metaprogramming library used in Kvasir. Having Kvasir as the only dependantcy (at least initially) allows us to experiment more freely with improvments in the metaprogramming field. 

A short list of key design decisions: 
- compile time speed above all else (especially for large lists)
- all eager interfaces (inspired by bronoco dutras metal)
- initally only trivial lambdas (as seen before in peter dimovs mp11 library)
