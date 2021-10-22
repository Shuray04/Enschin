#include "GameScene.h"

GameScene::GameScene()
{
    // m = new Model(new float[24] {
    //     -5.0f, -5.0f, 0.0f, 0.0f, // 0
    //     5.0f, -5.0f, 0.0f, 0.0f, // 1
    //     7.5f, 0.0f, 0.0f, 0.0f, // 2
    //     5.0f, 5.0f, 0.0f, 0.0f, // 2
    //     -5.0f, 5.0f, 0.0f, 0.0f,  // 3
    //     -7.5f, 0.0f, 0.0f, 0.0f  // 3
    // }, 6, new unsigned int[12]{
    //     1, 2, 3,
    //     0, 4, 5,
    //     0, 1, 3,
    //     0, 4, 3
    // }, 12);

    m1 = new Model(new float[24]{
       -60.0f, -50.0f, // 0
        50.0f, -50.0f,// 1
        60.0f, 50.0f, // 2
        -50.0f, 50.0f,// 3
    });
    // m = new Model(new float[20] {
    //     -5.0f, -0.5f, 0.0f, 0.0f, // 0
    //     0.5f, -0.5f, 0.0f, 0.0f, // 1
    //     0.5f, 0.5f, 0.0f, 0.0f, // 2
    //     0.0f, 0.75f, 0.0f, 0.0f, // 2
    //     -0.5f, 0.5f, 0.0f, 0.0f,  // 3
    // }, 5);
    // m = new Model(new float[16] {
    //     -0.6f, -0.5f, 0.0f, 0.0f, // 0
    //     0.5f, -0.5f, 1.0f, 0.0f, // 1
    //     0.6f, 0.5f, 1.0f, 1.0f, // 2
    //     -0.5f, 0.5f, 0.0f, 1.0f  // 3
    // });
    texi = new Texture("./res/textures/giordano.jpg");
}

void GameScene::update()
{
	//std::cout << "Hello Game" << std::endl;
}

void GameScene::render()
{
    // renderer.absoluteTranslate({0, 0.5f});
    // renderer.renderColor(*m, {1, 0, 1, 1});

    // renderer.absoluteTranslate({1, 0});
    // renderer.renderColor(*m, {0, 1, 1, 1});

    Renderer::translate({Mouse::getMousePos().x, Mouse::getMousePos().y});
    //Renderer::rotate(45.0f);
    Color c = Color(0, 1, 0, 1);
    Renderer::renderTexture(*m1, *texi);
    //Renderer::rotate(45.0f);
    Renderer::translate({Mouse::getMousePos().x*-1, Mouse::getMousePos().y*-1});
}