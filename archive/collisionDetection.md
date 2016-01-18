#Games Programming - Collision Detection


##Checking Complex Geometry - Optimization

- Checking entities with complex geometry against other entities is slow.
  - Exact pairwise collision detection

- which geometry is easy and/or cheap to check with what
  - separating plane methods
  - http://en.wikipedia.org/wiki/Gilbert%E2%80%93Johnson%E2%80%93Keerthi_distance_algorithm

- hierarchical bounding volumes

##Checking entity with entity - Optimization

Checking every entity against every other entity will work, but is highly inefficient when user with large numbers of entities

  - http://en.wikipedia.org/wiki/Triangular_number
    $$
      \frac{n(n+1)}{2}
    $$

- http://en.wikipedia.org/wiki/Sweep_and_prune

- Spatial partitioning


##Collision location (and other parameters)

##Collision response

http://en.wikipedia.org/wiki/Collision_response

