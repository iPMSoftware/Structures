#ifndef IPM_LIST
#define IPM_LIST

#include "../map/map.h"

namespace ipm {

    template<typename T, int SIZE = 100>
    class graph_2d {
        public:
        bool add_vertex(T vertex) {
            if(!has_vertex(vertex))
                return false;
            map_.put(vertex,size_++);
            return true;
        }
        bool add_edge(T vertex1, T vertex2) {
            if (bool hv = has_vertexes(vertex1,vertex2))
                return false;
            auto vertex1_id = map_.get(vertex1).val_;
            auto vertex2_id = map_.get(vertex2).val_;
            tab_[vertex1_id][vertex2_id] = true;
            size_++;
            return true;
        }
        bool delete_edge(T vertex1, T vertex2) {
            if(size_ == 0)
                return false;
            if(bool he = has_edge(vertex1,vertex2))
                return false;
            auto vertex1_id = map_.get(vertex1).val_;
            auto vertex2_id = map_.get(vertex2).val_;
            tab_[vertex1_id][vertex2_id] = false;
            return true;
        }

        int size() const {
            return size_;
        }
        private:
        struct vertex_index {
            static constexpr int kNoVertex {-1};
            int val_ {-1};

        };
        struct edge_indexes{
            vertex_index vertex1_;
            vertex_index vertex2_;
            bool is_connection() const {
                return (vertex1_.val_ != -1 && vertex2_.val_ != -1);
            }
        };
        bool has_edge(T vertex1, T vertex2) {
            if(!has_vertexes(vertex1,vertex2))
                return false;
            auto vertex1_id = map_.get(vertex1).val_;
            auto vertex2_id = map_.get(vertex2).val_;
            return tab_[vertex1_id][vertex2_id];
        }
        bool has_vertexes(T vertex1, T vertex2) {
            if(!has_vertex(vertex1))
                return false;
            if(!has_vertex(vertex1))
                return false;
            return true;
        }
        bool has_vertex(T vertex) {
            int vertex_id = map_.get(vertex).val_;
            if(vertex_id == edge_indexes::kNoVertex)
                return false;
            return true;
        }

        bool tab_[SIZE][SIZE];
        ipm::Map<T,vertex_index,SIZE> map_;
        int size_{0};
    };

    template<typename T, typename IMPL = ipm::graph_2d<T>>
    class graph {
        public:
        graph() = default;
        bool add_vertex(T vertex) {
            return impl_.add_vertex(vertex);
        }
        bool add_edge(T vertex1, T vertex2) {
            return impl_.add_edge(vertex1,vertex2);
        }
        bool delete_edge(T vertex1, T vertex2) {
            return impl_.delete_edge(vertex1,vertex2);
        }


        int size() const {
            return impl_.size();
        }

        

        private:
        IMPL impl_;
        int size_{0};

    };  

}

#endif