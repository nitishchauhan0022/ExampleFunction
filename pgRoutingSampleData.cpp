#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/hawick_circuits.hpp>
#include <boost/next_prior.hpp>
#include <boost/property_map/property_map.hpp>
#include <cstdlib>
#include <iostream>
#include <iterator>


template <typename OutputStream>
struct cycle_printer
{
    cycle_printer(OutputStream &stream)
        : os(stream)
    {
    }

    template <typename Path, typename Graph>
    void cycle(Path const &p, Graph const &g)
    {
        if (p.empty())
            return;
            
        // Get the property map containing the vertex indices
        // so we can print them.
        typedef typename boost::property_map<Graph, boost::vertex_index_t>::const_type IndexMap;

        IndexMap indices = get(boost::vertex_index, g);

        // Iterate over path printing each vertex that forms the cycle.
        typename Path::const_iterator i=p.begin(), before_end = boost::prior(p.end());

        for (; i != before_end; ++i)
        {
            os << get(indices, *i) << " ";
        }
       os << get(indices, *i) <<" ";
       os << get(indices, *p.begin()) << '\n';
    }
    
    OutputStream &os;
    
};



int main(int argc, char const *argv[])
{
  using namespace boost;
  using namespace std;
  typedef adjacency_list<vecS, vecS, bidirectionalS> Graph;

  typedef std::pair<std::size_t, std::size_t> Pair;
  Pair edges[17] = { Pair(1,2), 
                     Pair(2,5),  
                     Pair(3,6),  
                     Pair(4,9),
                     Pair(5,6),
                     Pair(5,10),  
                     Pair(6,9),  
                     Pair(6,11),
                     Pair(7,8),
                     Pair(8,5),
                     Pair(9,12),
                     Pair(10,11),
                     Pair(10,15),
                     Pair(11,12),
                     Pair(14,15),
                     Pair(15,13),
                     Pair(16,17)}; 

  Graph G(17);

  for (size_t i = 0; i < sizeof(edges)/sizeof(edges[0]); i++)
    add_edge(edges[i].first, edges[i].second, G).first;

    cycle_printer<std::ostream> visitor(std::cout);
    std::cout<<"Boost Graph hawick_circuits : \n";
    boost::hawick_circuits(G, visitor);

    std::cout<<"\nBoost Graph hawick_unique_circuits : \n";
    boost::hawick_unique_circuits(G, visitor);


    return EXIT_SUCCESS;
}