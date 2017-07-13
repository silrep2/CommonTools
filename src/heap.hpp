#ifndef SIL_HAEP
#define SIL_heap
#include <cstdlib>
namespace sil{

	template <typename Dtype>
	class heap{
	public:
		heap();
		~heap();
	private:
		Dtype *m_values;
		int m_size;
	};

	template <typename Dtype>
	heap<Dtype>::heap(){
		m_values = 0;
		m_size = 0;
	}

	template <typename Dtype>
	heap<Dtype>::~heap(){
		free(m_values);
	}
	
}


#endif