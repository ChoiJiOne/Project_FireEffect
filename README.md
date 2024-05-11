# Project - FireEffect
- 불 효과를 구현하는 프로젝트의 `0.0`입니다.
  - [다운로드 링크](https://github.com/ChoiJiOne/Project_FireEffect/releases/tag/0.0)
<br><br>


## Preview

![animation](./Image/animation.gif)

<br><br>


## Requirements
- Windows 10/11 Home/Pro
- [Git](https://git-scm.com/)
- [Visual Studio 2019 or 2022](https://visualstudio.microsoft.com/ko/)
- [CMake 3.27 or later](https://cmake.org/download/)
- [NSIS 3.09 or later](https://nsis.sourceforge.io/Download)

<br><br>


## How to get repository clone?

`CMD` 혹은 `PowerShell`에서 다음 명령어를 수행하시면 리포지토리의 복사본을 얻을 수 있습니다.

```PowerShell
git clone https://github.com/ChoiJiOne/Project_FireEffect --single-branch -b 0.0
```

<br><br>


## How to Generate Visual Studio Solution?

`CMD` 혹은 `PowerShell`에서 다음 명령어를 수행하시면 프로젝트의 Visual Studio 솔루션을 얻을 수 있습니다. 디렉토리 기준은 리포지토리의 복사본이 존재하는 폴더 기준입니다.

### Visual Studio 2019 
```
GenerateProjectFiles_vs2019.bat
```

### Visual Studio 2022
```
GenerateProjectFiles_vs2022.bat
```

> 위의 스크립트 모두 `CMD` 혹은 `PowerShell`에서 실행하지 않고 그냥 실행해도 동작합니다.

<br><br>


## How to Build Solution?

이 프로젝트는 Visual Studio를 실행하지 않은 상태에서 빌드할 수 있는 기능을 지원합니다. 빌드 스크립트가 지원하는 빌드 모드는 `Debug`, `Release`, `RelWithDebInfo`, `MinSizeRel`으로, 각각의 특징은 다음과 같습니다.

| mode | description |
|:---:|:---|
| Debug | 빌드 과정에서 최적화를 수행하지 않고, 디버그 정보 파일(.pdb)을 생성합니다. |
| Release | 빌드 과정에서 최적화를 수행하고, 디버그 정보 파일(.pdb)을 생성하지 않습니다. |
| RelWithDebInfo | 빌드 과정에서 최적화를 수행하고, 디버그 정보 파일(.pdb)을 생성합니다. |
| MinSizeRel  | 빌드 과정에서 최적화를 수행하고, 최소 크기로 최적화하며 디버그 정보 파일(.pdb)을 생성하지 않습니다. |

따라서, `CMD` 혹은 `PowerShell`에서 다음 명령어를 수행하시면 각 모드에 따라 빌드를 수행할 수 있습니다.

### Debug
```
Build_Debug.bat
```

### Release
```
Build_Release.bat
```

### RelWithDebInfo
```
Build_RelWithDebInfo.bat
```

### MinSizeRel
```
Build_MinSizeRel.bat
```

> 위의 스크립트 모두 `CMD` 혹은 `PowerShell`에서 실행하지 않고 그냥 실행해도 동작합니다.

<br><br>


## How to Package Project?

이 프로젝트는 사용자 머신에 프로젝트가 설치 가능하도록 하는 exe 파일을 생성할 수 있는 기능을 지원합니다. 이때, NSIS (nullsoft scriptable install system)가 설치되어 있고, 설치 경로가 환경변수에 등록되어 있어야 사용할 수 있습니다. 이 패키징 스크립트가 지원하는 모드는 `Debug`, `Release`, `RelWithDebInfo`, `MinSizeRel`으로 빌드 모드와 동일합니다. 따라서, `CMD` 혹은 `PowerShell`에서 다음 명령어를 수행하시면 각 모드에 맞는 패키지 파일을 얻을 수 있습니다.

> NSIS의 경로가 환경변수에 등록되어 있지 않으면 이 기능을 사용하실 수 없습니다. 

> 솔루션이 빌드되어 있어야 동작합니다. 빌드는 [여기](#how-to-build-solution)를 참조하세요.

### Debug
```
Package_Debug.bat
```

### Release
```
Package_Release.bat
```

### RelWithDebInfo
```
Package_RelWithDebInfo.bat
```

### MinSizeRel
```
Package_MinSizeRel.bat
```

> 위의 스크립트 모두 `CMD` 혹은 `PowerShell`에서 실행하지 않고 그냥 실행해도 동작합니다.

<br><br>


## 참고 자료
- [LearnOpenGL : Compute Shaders](https://learnopengl.com/Guest-Articles/2022/Compute-Shaders/Introduction)
- [Shadertoy - Fire Shader](https://greentec.github.io/shadertoy-fire-shader-en/)
- [The kernel is on fire](https://hugopeters.me/posts/8/)
