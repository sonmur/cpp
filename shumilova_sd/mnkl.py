import cairo


with cairo.SVGSurface("result.svg", 900, 600) as surf:
    ct = cairo.Context(surf)

    ct.set_source_rgba(0, .53, .32, 1)
    ct.rectangle(0, 0, 360, 640)
    ct.fill_preserve()
    ct.set_source_rgba(0, 0, 0, 0)
    ct.stroke()

    ct.set_source_rgba(.988, .819, .086, 1)
    ct.rectangle(360, 0, 640, 300)
    ct.fill_preserve()
    ct.set_source_rgba(0, 0, 0, 0)
    ct.stroke()

    ct.set_source_rgba(.909, .067, .176, 1)
    ct.rectangle(360, 300, 640, 300)
    ct.fill_preserve()
    ct.set_source_rgba(0, 0, 0, 0)
    ct.stroke()
