#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/hawick_circuits.hpp>
#include <boost/property_map/property_map.hpp>
#include <iostream>
#include <iterator>



struct circuit_printer
{
   
    template <typename Path, typename Graph>
    void cycle(Path const &p, Graph const &g)
    {
       if (p.empty())
            return;


        // Iterate over path printing each vertex that forms the circuit.
        typename Path::const_iterator i=p.begin(), end = p.end();

        for (; i != end; ++i)
        {
            std::cout<<*i<<" ";
        }
       std::cout<<*p.begin()<<std::endl;
    }
    
};



int main(int argc, char const *argv[])
{
  
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS> Graph;
  typedef std::pair<std::size_t, std::size_t> Pair;
   Pair edges[32] = { Pair(1,2),
                     Pair(2,1), 
                     Pair(2,5),
                     Pair(5,2),  
                     Pair(3,2),
                     Pair(3,6),
                     Pair(4,3),  
                     Pair(4,9),
                     Pair(9,4),
                     Pair(5,6),
                     Pair(6,5),
                     Pair(5,10), 
                     Pair(10,5),
                     Pair(5,8),
                     Pair(8,5),
                     Pair(6,9), 
                     Pair(9,6),
                     Pair(6,11),
                     Pair(7,8),
                     Pair(8,7),
                     Pair(9,12),
                     Pair(12,9),
                     Pair(10,11),
                     Pair(10,15),
                     Pair(15,10),
                     Pair(11,12),
                     Pair(13,15),
                     Pair(15,13),
                     Pair(14,15),
                     Pair(15,14),
                     Pair(16,17),
                     Pair(17,16)}; 

  Graph G(17);

  for (size_t i = 0; i < sizeof(edges)/sizeof(edges[0]); i++)
    boost::add_edge(edges[i].first, edges[i].second, G).first;

    circuit_printer visitor;

    std::cout<<"Boost Graph hawick_circuits : \n";
    boost::hawick_circuits(G, visitor);

    std::cout<<"\nBoost Graph hawick_unique_circuits : \n";
    boost::hawick_unique_circuits(G, visitor);



    return EXIT_SUCCESS;
}