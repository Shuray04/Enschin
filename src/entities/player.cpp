#include <game/player.h>

Player::Player(const UpdateContext& ctx, Vec2f pos)
    : GameObject(ctx, "Player", ctx.commonRes.getModel("test_model"), ctx.commonRes.getSprite("noah"), pos){
    jumpTimer = new Timer(0, .25f);
    ctx.camera.setCameraTarget(body);
}

void Player::update(const UpdateContext& ctx) {
    mousePos = ctx.input.getCursorPos();
    jumpTimer->update(ctx.deltaTime);
    if (ctx.input.isEvent("walk_forward") && jumps && jumpTimer->take()) {
        if (jumps >= 1) {
            body->SetLinearVelocity({body->GetLinearVelocity().x, 0});
            body->ApplyLinearImpulseToCenter({0, 25});
        }else{
            body->ApplyLinearImpulseToCenter({0, 25});
        }
        jumps--;
    }
    if (ctx.input.isEvent("walk_backwards")) {
        body->ApplyLinearImpulseToCenter({0, -12});
    }
    if (ctx.input.isEvent("walk_left")) {
        body->ApplyLinearImpulseToCenter({-40 * ctx.deltaTime, 0});
    }
    if (ctx.input.isEvent("walk_right")) {
        body->ApplyLinearImpulseToCenter({40 * ctx.deltaTime, 0});
    }

    if (ctx.input.isEvent("zoom_out")) {
        ctx.camera.increaseFov(ctx.window.getSize(), ctx.deltaTime * 10);
    }

    if (ctx.input.isEvent("zoom_in")) {
        ctx.camera.increaseFov(ctx.window.getSize(), -ctx.deltaTime * 10);
    }
}


void Player::onCollision(const GameObject* go) {
    jumps = maxJumps;
}