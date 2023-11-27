import os
import re

SrcPath=os.environ["SourcePath"]
BuildNum=os.environ["BuildNum"]
SrcLocation="develop\\global\\src"

SConstructFile="SConstruct"
SConstructPattern="point\=[\d]+"
SConstruct_ReplaceBuildString="point="+BuildNum

VersionFile="VERSION"
VersionPattern="ADLMSDK_VERSION_POINT=[\d]+"
Version_replaceBuildString="ADLMSDK_VERSION_POINT="+BuildNum

def updateBuildNumber(sourcePath,location,filename,pattern,replaceBuildStr):
    fullPath=os.path.join(sourcePath,location,filename)
    os.chmod(fullPath, 755)
    fin =open(fullPath, 'r')
    fout=open(fullPath+"1",'w')
    for line in fin:
        if(re.search(pattern,line)):
            line=re.sub(pattern,replaceBuildStr,line)
        fout.write(line)
    fin.close()
    fout.close()
    os.remove(fullPath)
    os.rename(fullPath+"1",fullPath)

def main():
    updateBuildNumber(SrcPath,SrcLocation,SConstructFile,SConstructPattern,SConstruct_ReplaceBuildString)
    updateBuildNumber(SrcPath,SrcLocation,VersionFile,VersionPattern,Version_replaceBuildString)
    
main()
