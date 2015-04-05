
class Cell
{
	bool* cell_neighbors;
	bool alive;
public:
	Cell();
	Cell(bool* obj);
	bool func_alive();
	bool cell_death();
	bool cell_alive();
};
