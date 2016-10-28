#pragma once

#include <mbgl/renderer/bucket.hpp>
#include <mbgl/map/mode.hpp>
#include <mbgl/tile/geometry_tile_data.hpp>
#include <mbgl/gl/vertex_buffer.hpp>
#include <mbgl/gl/index_buffer.hpp>
#include <mbgl/gl/segment.hpp>
#include <mbgl/programs/circle_program.hpp>
#include <mbgl/style/layers/circle_layer_properties.hpp>

namespace mbgl {

class CircleBucket : public Bucket {
public:
    CircleBucket(style::CirclePaintProperties::Evaluated, float z, MapMode);

    void upload(gl::Context&) override;
    void render(Painter&, PaintParameters&, const style::Layer&, const RenderTile&) override;

    bool hasData() const override;
    void addFeature(const GeometryTileFeature&,
                    const GeometryCollection&);

    gl::VertexVector<CircleLayoutVertex> vertices;
    gl::IndexVector<gl::Triangles> triangles;
    gl::SegmentVector<CircleAttributes> segments;

    optional<gl::VertexBuffer<CircleLayoutVertex>> vertexBuffer;
    optional<gl::IndexBuffer<gl::Triangles>> indexBuffer;

    CircleProgram::PaintPropertyBinders paintPropertyBinders;

    const MapMode mode;
};

} // namespace mbgl
