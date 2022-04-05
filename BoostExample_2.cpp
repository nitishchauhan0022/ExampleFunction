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

        
        // Iterate over path printing each vertex that forms the cycle.
        typename Path::const_iterator i=p.begin(), before_end = p.end();

        for (; i != before_end; ++i)
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
  Pair edges[6] = { Pair(0,1), 
                     Pair(1,2),  
                     Pair(2,3),  
                     Pair(2,4),  
                     Pair(3,4),  
                     Pair(4,1)}; 

  Graph G(5);

  for (size_t i = 0; i < sizeof(edges)/sizeof(edges[0]); i++)
        boost::add_edge(edges[i].first, edges[i].second, G).first;

        
    circuit_printer visitor;
    std::cout<<"Boost Graph hawick_circuits : \n";
    boost::hawick_circuits(G, visitor);

    std::cout<<"\nBoost Graph hawick_unique_circuits : \n";
    boost::hawick_unique_circuits(G, visitor);


    std::cout<<"\nAdding Parallel edges 4->5 \n";
    add_edge(2,3,G);

    std::cout<<"\nBoost Graph hawick_circuits after adding parallel edge : \n";
    boost::hawick_circuits(G, visitor);

    std::cout<<"\nBoost Graph hawick_unique_circuits after adding parallel edge: \n";
    boost::hawick_unique_circuits(G, visitor);


    return EXIT_SUCCESS;
}