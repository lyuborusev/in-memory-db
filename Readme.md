# In-Memory DB

The codebase contains few implementations utilizing different strategies for implementing an in-memory table/collection of records supporting searching funcitonality over the values.

The Record object is containing fields of different types. Also the database supports searching over all fields. Therefore it is hard to decide how to sort the records of the collection to improve searching performance. Hence we're going to use a simplistic linear search and will try to micro-optimize the operations facilitating the linear search.

## Strategy

The algorithms are organised using the Strategy Design Pattern implemented using static polymorphism and templates.

### BaseStrategy

The basic implementation was provided as a benchmark startpoint.

### CompareFunStrategy

An obvious improvement was to move out the branch-condition selecting the current column outside the loop iterating over the values

### SOALayouStrategy

It is worth to benchmark if a Structure of Arrays (SOA) memory layout will have performance improvements over using Array of Structures (AOS) layout. In this particular case it appeared that the SOA introduced performance enhancements.

### SOAGenericStrategy

A generic implementation of the SOA memory layout approach, encapsulating some of the implementation details.