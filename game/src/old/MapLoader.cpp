#include "MapLoader.h"
#include <fstream>
#include <string>

MapLoader::MapLoader(std::string fileName,MapData& map_data)
{
    std::ifstream file(fileName);
    if(file.is_open())
    {
        std::cout<<"The file "<<fileName<<" is opend"<<std::endl;
        bool isValid=false;
        std::string line;
        while(std::getline(file,line))
        {
            if (!isValid)
            {
                if(line=="[Map]")
                {
                    isValid=true;
                    continue;
                }
                else
                {
                    std::cout<<"The file "<<fileName<<" is not valid "<<std::endl;
                    file.close();
                    break;
                }
            }
            else
            {
                int count=line.find('=');
                std::string varaible=line.substr(0,count);
                std::string value=line.substr(count+1,line.length()-count);
                if(varaible=="tile-sheet"){map_data.tileSheet=value;}
                else if(varaible=="name"){map_data.mapName=value;}
                else if(varaible=="version"){map_data.version=std::stoi(value);}

                else if(varaible=="cellSizeX"){map_data.cellSizeX=std::stoi(value);}
                else if(varaible=="cellSizeY"){map_data.cellSizeY=std::stoi(value);}

                else if(varaible=="mapPositionX"){map_data.mapPositionX=std::stoi(value);}
                else if(varaible=="mapPositionY"){map_data.mapPositionY=std::stoi(value);}

                else if(varaible=="mapWidth"){map_data.mapWidth=std::stoi(value);}
                else if(varaible=="mapHeight"){map_data.mapHeight=std::stoi(value);}


                else if(varaible=="mapScaleX"){map_data.mapScaleX=std::stoi(value);}
                else if(varaible=="mapScaleY"){map_data.mapScaleY=std::stoi(value);}

                else if(varaible=="rows"){map_data.totalCellsX=std::stoi(value);}
                else if(varaible=="cols"){map_data.totalCellsY=std::stoi(value);}

                else if(varaible=="dataNumber"){map_data.dataNumber=std::stoi(value);}
                else if(varaible=="data")
                {
                    map_data.data=new int[map_data.dataNumber];
                    int start=count;
                    int offset;
                    for(int i=0;i<map_data.dataNumber;i++)
                    {
                        
                        if(i==map_data.dataNumber-1){offset=line.find(';',start+1);}

                        else{offset=line.find(',',start+1);}
                       
                        value=line.substr(start+1,offset-start-1);
                        map_data.data[i]=std::stoi(value);
                        start=offset;
                    }
                }
            }
        }
        file.close();
    }
    
}



