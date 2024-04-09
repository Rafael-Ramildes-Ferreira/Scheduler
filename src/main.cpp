class AbstractScheduler {
	public:
		virtual int swap_context();
		virtual int get_time_quanta();
		virtual int set_time_quanta(int quanta);
};

int main(int argc, char* argv[]){
	return 0;
}