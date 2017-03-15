#ifndef UTILITY_H
#define UTILITY_H

#define MakroNewCell(baris)						\
{																			\
	switch (baris) {  									\
    case 'W':													\
      cells[i][j] = new Habitat('W');	\
      break;													\
    case 'A':													\
      cells[i][j] = new Habitat('A');	\
      break;													\
    case 'L':													\
      cells[i][j] = new Habitat('L');	\
      break;													\
    case 'X':													\
      cells[i][j] = new Road('X');		\
      break;													\
    case 'N':													\
      cells[i][j] = new Road('N');		\
      break;													\
    case 'r':													\
      cells[i][j] = new Road('r');		\
      break;													\
    case 'R':													\
      cells[i][j] = new Restaurant();	\
      break;													\
    case 'P':													\
      cells[i][j] = new Park();				\
      break;													\
  }																		\
}

#define MakroNewAnimal(id,weight)						 													\
{																																			\
	if (id == "WF") {																										\
	  Wolf* pa;																													\
	  if (weight != 0) pa = new Wolf(weight,make_pair(py,px));					\
	  else pa = new Wolf(make_pair(py,px));															\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "LI") {																							\
	  Lion* pa;																													\
	  if (weight != 0) pa = new Lion(weight,make_pair(py,px));					\
	  else pa = new Lion(make_pair(py,px));															\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "ZBR") {																							\
	  Zebra* pa;																												\
	  if (weight != 0) pa = new Zebra(weight,make_pair(py,px));					\
	  else pa = new Zebra(make_pair(py,px));														\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "ELP") {																							\
	  Elephant* pa;																											\
	  if (weight != 0) pa = new Elephant(weight,make_pair(py,px));			\
	  else pa = new Elephant(make_pair(py,px));													\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "MCQ") {																							\
	  Macaque* pa;																											\
	  if (weight != 0) pa = new Macaque(weight,make_pair(py,px));				\
	  else pa = new Macaque(make_pair(py,px));													\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "HG") {																							\
	  Hog* pa;																													\
	  if (weight != 0) pa = new Hog(weight,make_pair(py,px));						\
	  else pa = new Hog(make_pair(py,px));															\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "EGL") {																							\
	  Eagle* pa;																												\
	  if (weight != 0) pa = new Eagle(weight,make_pair(py,px));					\
	  else pa = new Eagle(make_pair(py,px));														\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "OW") {																							\
	  Owl* pa;																													\
	  if (weight != 0) pa = new Owl(weight,make_pair(py,px));						\
	  else pa = new Owl(make_pair(py,px));															\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "HMB") {																							\
	  Hummingbird* pa;																									\
	  if (weight != 0) pa = new Hummingbird(weight,make_pair(py,px));		\
	  else pa = new Hummingbird(make_pair(py,px));											\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "CKT") {																							\
	  Cockatoo* pa;																											\
	  if (weight != 0) pa = new Cockatoo(weight,make_pair(py,px));			\
	  else pa = new Cockatoo(make_pair(py,px));													\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "RBN") {																							\
	  Robin* pa;																												\
	  if (weight != 0) pa = new Robin(weight,make_pair(py,px));					\
	  else pa = new Robin(make_pair(py,px));														\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "BT") {																							\
	  Bat* pa;																													\
	  if (weight != 0) pa = new Bat(weight,make_pair(py,px));						\
	  else pa = new Bat(make_pair(py,px));															\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "SHK") {																							\
	  Shark* pa;																												\
	  if (weight != 0) pa = new Shark(weight,make_pair(py,px));					\
	  else pa = new Shark(make_pair(py,px));														\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "MRE") {																							\
	  MorayEel* pa;																											\
	  if (weight != 0) pa = new MorayEel(weight,make_pair(py,px));			\
	  else pa = new MorayEel(make_pair(py,px));													\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "DGG") {																							\
	  Dugong* pa;																												\
	  if (weight != 0) pa = new Dugong(weight,make_pair(py,px));				\
	  else pa = new Dugong(make_pair(py,px));														\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "TRL") {																							\
	  Turtle* pa;																												\
	  if (weight != 0) pa = new Turtle(weight,make_pair(py,px));				\
	  else pa = new Turtle(make_pair(py,px));														\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "DLP") {																							\
	  Dolphin* pa;																											\
	  if (weight != 0) pa = new Dolphin(weight,make_pair(py,px));				\
	  else pa = new Dolphin(make_pair(py,px));													\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "WHL") {																							\
	  Whale* pa;																												\
	  if (weight != 0) pa = new Whale(weight,make_pair(py,px));					\
	  else pa = new Whale(make_pair(py,px));														\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "PNG") {																							\
	  Penguin* pa;																											\
	  if (weight != 0) pa = new Penguin(weight,make_pair(py,px));				\
	  else pa = new Penguin(make_pair(py,px));													\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "HPP") {																							\
	  Hippopotamus* pa;																									\
	  if (weight != 0) pa = new Hippopotamus(weight,make_pair(py,px));	\
	  else pa = new Hippopotamus(make_pair(py,px));											\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "PLC") {																							\
	  Pelican* pa;																											\
	  if (weight != 0) pa = new Pelican(weight,make_pair(py,px));				\
	  else pa = new Pelican(make_pair(py,px));													\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "GSE") {																							\
	  Goose* pa;																												\
	  if (weight != 0) pa = new Goose(weight,make_pair(py,px));					\
	  else pa = new Goose(make_pair(py,px));														\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "CRN") {																							\
	  Crane* pa;																												\
	  if (weight != 0) pa = new Crane(weight,make_pair(py,px));					\
	  else pa = new Crane(make_pair(py,px));														\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "DRL") {																							\
	  DracoLizard* pa;																									\
	  if (weight != 0) pa = new DracoLizard(weight,make_pair(py,px));		\
	  else pa = new DracoLizard(make_pair(py,px));											\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "CLG") {																							\
	  Colugo* pa;																												\
	  if (weight != 0) pa = new Colugo(weight,make_pair(py,px));				\
	  else pa = new Colugo(make_pair(py,px));														\
	  AddAnimal(pa);																										\
	}																																		\
	else if (id == "SGL") {																							\
	  SugarGlider* pa;																									\
	  if (weight != 0) pa = new SugarGlider(weight,make_pair(py,px));		\
	  else pa = new SugarGlider(make_pair(py,px));											\
	  AddAnimal(pa);																										\
	}																																		\
}

#endif