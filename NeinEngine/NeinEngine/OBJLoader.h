#ifndef OBJLoaderX
#define OBJLoaderX
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;
#define TOKEN_VERTEX_POS "v"
#define TOKEN_INDEX_V "f"
#define LIMIT 1000
class OBJLoader{
	static vector<PositionVertex> positions;
	static vector<int> indices;
public:
	static void LoadMesh(string fileName,Mesh<PositionVertex> *ret){
		positions.clear();
		indices.clear();
		ifstream fileStream;
		fileStream.open(fileName.c_str());

		string lineStream;
		while(getline(fileStream,lineStream)){
			stringstream str_stream(lineStream);
			string type_str;
			str_stream>>type_str;
			if(type_str == TOKEN_VERTEX_POS){
				Vector3 pos;
				str_stream>>pos.x>>pos.y>>pos.z;
				positions.push_back(PositionVertex(pos));
			}else if(type_str == TOKEN_INDEX_V){
				int i1,i2,i3;
				str_stream>>i1>>i2>>i3;
				indices.push_back(i1);
				indices.push_back(i2);
				indices.push_back(i3);
			}
		}
		fileStream.close();
		PositionVertex *VData=&positions[0];
		int *IData=&indices[0];
		ret->addVertices(VData,positions.size(),IData,indices.size());
	}
};
vector<PositionVertex> OBJLoader::positions = vector<PositionVertex>();
vector<int> OBJLoader::indices = vector<int>();
#endif