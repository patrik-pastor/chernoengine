//
// Created by shepherd on 17.3.23.
//

#ifndef CHERNOENGINE_ORTHOGRAPHIC_CAMERA_HPP
#define CHERNOENGINE_ORTHOGRAPHIC_CAMERA_HPP

#include <glm/glm.hpp>

namespace chernoengine {

class OrthographicCamera {
public:
    OrthographicCamera(float left, float right, float bottom, float top);

    const glm::vec3& GetPosition() const;

    void SetPosition(const glm::vec3& position);

    float GetRotation() const;

    void SetRotation(float rotation);

    void SetProjection(float left, float right, float bottom, float top);

    const glm::mat4& GetProjectionMatrix() const;

    const glm::mat4& GetViewMatrix() const;

    const glm::mat4& GetViewProjectionMatrix() const;

private:
    void RecalculateViewMatrix();

    glm::mat4 projection_matrix_;
    glm::mat4 view_matrix_;
    glm::mat4 view_projection_matrix_;
    glm::vec3 position_ = {0.0f, 0.0f, 0.0f};
    float rotation_ = 0.0f;
};

} // chernoengine

#endif //CHERNOENGINE_ORTHOGRAPHIC_CAMERA_HPP
