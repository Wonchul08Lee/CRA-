# CRA-

과정 링크 : https://gist.github.com/mincoding1/05db2905c2647dc5f4a33ce81bd6a8b6

[Project발표.pdf](https://github.com/user-attachments/files/19604247/Project.pdf)

[SSD_Project.pdf](https://github.com/user-attachments/files/19604248/SSD_Project.pdf)

[SSD_Project2.pdf](https://github.com/user-attachments/files/19604249/SSD_Project2.pdf)

[발표양식.pptx](https://github.com/user-attachments/files/19604251/default.pptx)




#교육 내용

##[Day1]
1. Clean code  : 객체지향 패러다임
   - 가독성
   - 안전성 -> 은닉, validcheck, pre-condition, 안전한 C++ 문법 사용
   - 유지보수성 -> 객체지향 스럽게 개발, 의존도 낮추고, interface 적절히 도입, capsule 화, DI, Factory


##[Day2]
1. 캡슐화
- 외부에서 관심이 없는것을 완전 숨기고 
   접근 가능한것만 접근 하도록 한다. 

- 방어적 프로그램을 위해서 
  1) 밖에서 건드리면 안되는 변수/함수 private 처리
  2) 파리미터로 들어온 변수 유효성 검사 (valid check)
  3) 호출 가능한 상황인지 확인하는 검증 - precondition check


2. 상속
   기반 또는 상위 클래스 (base class, super class, subclass, 파생(derived) class)
   상속을 쓰는 이유
    - 중복 제거 
    - 계층 구조 표현 하고자 ---> 실제는 많지 않다. 

    다양한 하위 타입이 참조될 수 있는 성질 -> 다형성
      - DI (dependency Injection)
      - Factory
     DI/Factory 는 code 로 실습이 있음. 

     상속 + 추상화로 다형성 구현이 가능 
    다형성은 clean code 에서 언제 사용하나?  -> DI/Factory 로 의존 복잡성을 낮출때 쓴다. 

3. Smart pointer
unique-ptr : 한 포인터만 소유권을 가진다. 
shared-ptr : 여러 포인터가 소유권을 가진다. -> 현실적으로는 shared-ptr만 사용해도 됨. 

##[Day3]
* 함수형 프로그래밍 패러다임
-> [1]how가 아닌 what 에 집중
    뭘 구현할건지 적는것에 집중하고, 세부 알고리즘 숨기는것
-> 선언적 프로그래밍 지향

[2]Side effect없는 "순수함수" 를 이용  
           - 버그 발생 가능성 적다. 
           - 버그 발생되더라도 내부에서만 고치면된다. 
           - thread로 병렬 처리 가능
    
     side effect : 외부에 있는 data를 변경할때 side effect 가 발생했다 함. 
     side effect 가 있는 함수 -> 외부값을 변경하는 함수
     side effect 가 없는 함수 -> 순수 함수 (함수형 프로그래밍에서는 순수 함수를 적극적으로 쓰자)
    ->  순수 함수처럼 이름 지었으면(get**()), 순수 함수로 동작해야 예측성을 높일 수 있다. 
      

* Unit Test 의 의미
 - 비용의 최소화   -> SW 공학적인 면에서 비용은 '인건비'
   clean 코드로 기능추가도 빠르게, 버그 확률 낮출 수 있다 -> SW 비용이 낮아지니깐. clean code, 리팩토링 하는 이유이다.
- 검증하는 역할도 하지만, 샘플 코드 역할 도 한다. 

* Refactoring
  clean code로 refactoring하고 -> 기능 추가해야 효율

* coverage 
         OpenCppCoverage.exe --sources K:*.cpp --export_type=html:coverage -- .\x64\Debug\ALU.exe
   refactoring 개념에서, 전/후 결과를 동일하게 나오는지 검증용으로 최소한 code coverage 100% Unit test 준비하는것을 권장 -> (골든마스터 테스트)



##[Day4]
method 레벨 리펙토링을 클린코드로 명확히 한 후 -> 객체지향 패러다임 적용하여 리팩토링!

##[Day5, SOLID, Refactoring]
좋은 소프트웨어 설계의 시작 
- 모듈화, 결합도, 응집도
- 추상화, 캡슐화, 상속, 다형성

OOP에서의 추상화 -> interface 사용

* 관계 : Solid 이론은, code 로 이해 -> Day5 Solid solution 확인
   상속의 강도
  => Generalization - Composition- Aggregation- association - dependency 

* SOLID 
   SRP, OCP, LSP, ISP, DIP
   1) SRP : 모든 클래스는 하나의 책임만 가진다. 
      책임 : "기능"보다는 더 큰 범주가 필요하고, "임무" (책임) 으로 개념화
                암살자 임무 = 여러가지 행동(기능) -> 몰래 걷기, 암살하기, ....
   2) OCP : interface 를 통해 확장성 고려

   3) LSP
      상위 클래스가 파라미터로 있을때, 모든 하위클래스는 대입될 수 있어야한다. 
   4) ISP : interface 분할
   5) D : DIP interface로 의존성 낮춤


* 리팩토링을 언제 하는가? 
1. TDD 할때. -> TDD 안에서 리팩토링하는것을, "TDD 리팩토리" 이라고 부르겠다. 
2. 맘에 안드는 코드를 볼때  -> 쓰레기줍기 리팩토링
   - 잘 동작되더라도 리팩토링은 필요, 항시 진행
3. 이해안가는 코드 -> 이해하기 힘든 리팩토링
4. 기능추가하기 전에. 


##[Day6, design pattern]
* GOF
생성패턴 : instance 생성할때 사용 (factory method pattern, singleton pattern)
구조패턴
행동패턴 : command pattern

1) Factory method pattern
직접 생성자 사용경우, 
- 직접적인 생성자를 호출하기에, 생성자에 대한 의존성이 생긴다. 
- 생성이 복잡하다. 
=> 가상 생성자 이용 (factory method)
  class Something {
public:
	Something() = default();
만약 Something(int ml);
}
int main(){
	Something t;
또는 Something *t = new Something();		=> 의존성

	Something(385);			=> 사전 지식하또는 특정 조건으로 사용해 복잡하다는 의미. 
}


2) Builder pattern
다량의 설정값이 있을때 사용
named parameter 가 없으면, 함수의 변수가 많을 수록 복잡하고 실수할 수가 있다. 
func(5, 7, 8, 7) -> named parameter 일때는, func(x=5, y=7, ...) 이다. 
설정값을 세팅할때, named parameter 형태로 이용
abc.height();
abc.weight();
abc.age();

3) Singleton pattern
단 하나의 instance 만 사용하는 패턴
static 사용 -> 전역변수처럼, instance 생성없이 접근 가능

4) Command pattern 
명령측과 실행측의 결합 분리
Invoker/Command/ConcreteCommand/Receiver 를 통해 다양한 receiver 가 오더라도 사용 가능. 
class diagram 으로 생각하면, receiver의 동작은 concreteCommand 에 가려져 있다. 


[refactoring point]
1. 유사 기능들을 class 형태로, 점진적 변경
2. 중복 코드 제거, 조건에 따른 변화 여부 파악

##[Day7. Git]
git visual 학습 사이트 : https://git-school.github.io/visualizing-git/

[Local repository]                [Remote repository]
commit              -->(push)     
                       <--(pull)
선택한 작업을 "staging 한다" -> git add

$ git remote add origin https://github.com/Wonchul08Lee/git_test.git
   local 을 retmote (origin = http://...) 에 연동하겠다. 
$git push -u origin master  
  1회 origin 을 master 로 설정하고, 이후는 git push 만 하면 됨. 
$git fetch : remote repo 최신 정보를 가져오는것
$git pull :remote repo 최신 commit 를 가져오는것
$git clone : git init + remote 세팅 + pull까지해주는 것


git 에서는
   - master branch 로 checkout하고 git merge 병합
github에서는
   - feature branch 로 개발 끝나면, master branch 관리자에게 병합 요청 => pull request



##[Day8, TDD]
TC 개발 -> TC pass 목적으로 코드 개발(완벽할 필요는 없다, production code) -> Refactoring 한다. (Refactor 단계)
(RED)                          (GREEN)                                                                     (Refactor)
class 껍질등 뼈대코드 정도는 만들고, TC 개발한다. 
이 과정이 반복!

- TC 개발 : UT는 To do list 이며, 뭘할지에 대해서만 집중!
- 구현 : Pass 만 목적!
- Refactoring mode : clean code 가 되도록 집중

*TDD 장접
- TC fail 난것으로 인해 할일이 명확해진다. (명확한 요구사항)
- 테스트가 고려된 독립성이 큰 모듈들이 만들어진다. (자연스러운 모듈화로 객체지향 패러다임이 잘 지켜진다.)
	Unit test 쉬운 모듈 : loosed coupling, 응집도 높은 모듈
- 사소한 bug 줄어든다. (품질 확보)
- code coverage 확보
* TDD 단점
- TC case 가 많고, TC 만들기 어려운 기능이 있기에, 비용이 커질 수 있다. 

=> 품질 & 신뢰성이 요구되는 큰 프로젝트에서는 TDD 의 장점이 더 돋보인다. 
=> 신규 feature 로 인해, 기존 code 가 망가져서 불량나는것은, UT를 통한 Regression test 로 관리가 가능하다. 


##[Day9, TDD, test double]
Fake : 실물을 가짜로 만든것 (simulator)
Mock object : 쉽게 만드는 간단한 가짜 객체
마틴 파울러의 이론으로 설명 : Dummy, Stub, Spy, mock, fake ...
   -> spy 를 안쓰고, mock 을 쓰는 이유는 빠른 테스트를 위해서이다. 
실무 : Fake/Mocking 위주로 진행

EXPECT_CALL(callmock, getSum(_,_))  : 행동 검증 (mocking 으로 행동 검증이가능)
EXPECT_EQ() : 상태 검증

* Mock 주입
- interface 를 도입

##[Day10, 좋은 Unit test]
* 거짓 양성 : fail 발생했지만, 살펴보니 fail 이 아닌 경우 (양치기 소년 Unit Test)
* 안좋은 Unit test 
   - 함수가 특정 순서대로 호출되어야 하는 경우 -> 리팩토링으로 내부 함수 호출 순서가 변경되기도 하기때문
   - 함수가 N회이상 호출되어야 하는 경우 -> method 분할/제거하는 리팩토링하기 때문에


* 좋은 unit test
   - 회귀 방지 : 신규 기능을 추가했는데, 기존 코드가 망가지는 것을 회귀라고 하고 이를 UT로 방지 할 수 있다. (코드 커버리지가 높도록 한다.)
   - 회귀 버그 방지를 잘 할 수 있도록 Unit 자체 커버리지가 높은것
   - 리팩토링 내성이 좋고 (mocking을 쓰면 리팩토링 내성이 안좋을 수 있으니 주의는 필요)
   - 빠른 UT
 





