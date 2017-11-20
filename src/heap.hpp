#ifndef SIL_HAEP
#define SIL_heap
#include <cstdlib>
namespace sil{

	template <typename Dtype>
	class heap{
	public:
		heap();
		~heap();
		void resize(int size);
	private:
		Dtype *m_values;
		int m_size;
		int m_capacity;
		void reallocate(int size);
		inline int left_child(int x);
		inline int right_child(int x);
	};

	template <typename Dtype>
	heap<Dtype>::heap(){
		m_values = 0;
		m_size = 0;
		m_capacity = 0;
	}

	template <typename Dtype>
	heap<Dtype>::~heap(){
		free(m_values);
	}
	
	template <typename Dtype>
	void heap<Dtype>::resize(int size) {
		if(size <= m_capacity)
			return;
		else	
			reallocate(size);
	}

	template <typename Dtype>
	void heap<Dtype>::reallocate(int size) {
		Dtype *new_space = malloc(size * sizeof(Dtype));
		memcpy(new_space, m_values, m_size * sizeof(Dtype));
		free(m_values);
		m_values = new_space;
	}
	template <typename Dtype>
	inline int heap<Dtype>::left_child(int x) {
		return (x<<1)+1;
	}
	template <typename Dtype>
	inline int heap<Dtype>::right_child(int x) {
		return (x<<1)+2;
	}
}


#endif